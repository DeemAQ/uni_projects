'''
--------------- CSC 386 ---------------
-STUDENT NAME-            -STUDENT ID-
Leena Alzkeri              439201239
Ghadah Alsuhaibani         439200798
Deem Alqudaimi             439201062
Ruba Almutairi             439200752
-----------------------------------------
'''

# ------------------ CLASS 1 ------------------
class Transaction:
   def __init__(self, id, TS):  
     self.id = id
     self.TS = TS
    
   def getId(self):
     return self.id

   def getTS(self):
     return self.TS

   def setId(self, id):
     self.id = id

   def setTS(self, TS):
     self.TS = TS
  
   def __repr__(self):
        return f'Transaction_{self._id}, Time Stamp = {self._TS}'



# ------------------ CLASS 2 ------------------
class Item:
  def __init__(self, RTS, WTS, key):
    self.RTS = RTS
    self.WTS = WTS
    self.key = key

  def setRTS(self, RTS):
    self.RTS = RTS
     
  def setWTS(self, WTS):
    self.WTS = WTS

  def setKey(self, key):
    self.key = key 

  def getRTS(self):
    return self.RTS

  def getWTS(self):
    return self.WTS

  def getKey(self):
    return self.key



# ------------------ Lists and flags ------------------
transactions_list = [] # ongoing transactions .. list of type transaction
items_list = [] # list of item versions .. list of type item
serial_oper_list = [] # to find the equivalent serial schedule
serial_Tnum_list = [] # to find the equivalent serial schedule
global flagAbort
flagAbort = False


# ------- METHOD 1 : begin -------
def begin(id, TS):
    
    transaction = Transaction(id, TS) # Create object
    transactions_list.append(transaction) # Insert in transactions list
    serial_Tnum_list.append(id)# To uset it later for serial schedule
    serial_oper_list.append(line)# To uset it later for serial schedule


# ------- METHOD 2 : read -------
def read(id, key):
    
    serial_Tnum_list.append(id)# To uset it later for serial schedule
    serial_oper_list.append(line)# To uset it later for serial schedule
  
    TS = 0
    
    # To find TS(Ti)
    for transaction in transactions_list:
        if (transaction.getId() == id):
            TS = transaction.getTS()
  
    flag = False
    for item in items_list:
        if item.getKey() == key:
            flag = True
            break
    
    if flag == False:
        items_list.append(Item(0, 0, key))
    
    temp = key + str('0')
    for item in reversed(items_list):
        if ((temp == item.getKey() or key == item.getKey()) and TS >= item.getWTS()):# To find the correct version
            item.setRTS(max(item.getRTS(), TS))
            return


# ------- METHOD 3 : write -------
def write(id ,key, time):
    
    serial_Tnum_list.append(id)# To uset it later for serial schedule
    serial_oper_list.append(line)# To uset it later for serial schedule
  
    Ti = None
    TS = 0
    # To find TS(Ti)
    for transaction in transactions_list:
        if (transaction.getId() == id):
            Ti = transaction
            TS = transaction.getTS()
    
    flag = False
    for item in items_list:
        if item.getKey() == key:
            flag = True
            break
    
    if flag == False:
        items_list.append(Item(0, 0, key))
    
    temp = key + str('0')
    for item in reversed(items_list):
        if ((temp == item.getKey() or key == item.getKey()) and TS >= item.getWTS()):# To find the correct version
            if(TS < item.getRTS()):
                abort(Ti, time) 
            elif TS >= item.getRTS():
                new_item = Item(TS, TS, key+str('0'))
                items_list.append(new_item)# Create new version
                return


# ------- METHOD 4 : commit -------
def commit(id):
    
  serial_Tnum_list.append(id)# To uset it later for serial schedule
  serial_oper_list.append(line)# To uset it later for serial schedule

 # To find Transaction
  for transaction in transactions_list:
    if (transaction.getId == id):
      Ti = transaction
      transactions_list.remove(Ti)
      break


# ------- METHOD 5 : abort -------
def abort(Transaction, time):
    
    global flagAbort 
    flagAbort = True
    transactions_list.remove(Transaction)
    print(f"Transaction {Transaction.id} abort in time {time}")



# ------- main function -------
def main():
    # CHANGE IT TO : schedule1.txt, schedule2.txt, schedule3.txt, schedule4.txt
    with open('schedule3.txt') as f:
      line_count = 1
      
      
      for line in f:
        _ = line.find('_')
        left_paran = line.find('(')


        if 'begin' in line:
          id = int(line[_+1:])
          begin(id, line_count)

        if 'commit' in line:
          id = int(line[_+1:])
          commit(id)

        if 'read' in line:
          id = int(line[_+1:])
          key = line[left_paran+1:left_paran+2]
          read(id, key)

        if 'write' in line:
          id = int(line[_+1:])
          key = line[left_paran+1:left_paran+2]
          write(id, key, line_count)
        
        
        line_count = line_count + 1

    # Serial schedule
    if flagAbort:
     print("There is no equivalent serial schedule")
    else:
        print("The equivalent serial schedule:")
        serial_schedule = list(zip(serial_oper_list, serial_Tnum_list)) #[(begin_1 ,1),(read(Z )_3 ,3),(commit_1,1)]
        for i in range(1, len(transactions_list) + 1):
            for j in range(len(serial_schedule)):
                if serial_schedule[j][1] == i:
                    print(serial_schedule[j][0])

if __name__=="__main__":
    main()
    