# project3-HDD-ScanCScan
Problem Description  
You are to implement a program that would solve questions like the one below: 
On  a  traditional  magnetic  hard  disk  drive  with  300  cylinders,  a  file  transfer  requires  access  to  the 
cylinders in the following fashion:  
121, 37, 98, 122, 89, 14, 156, 201, 67, 288 
Indicate  the  head  travel  sequence  in  the  order  of  cylinders  covered  for  SCAN  and  C-SCAN 
algorithms. Also report the total head movement for all the algorithms, assuming that the head is over 
cylinder 132 at the start and going towards 300. 
The list of requirements are as follows: 
 
General requirements for the program: 
1. The  program  then  asks  the  initial  cylinder  location  of  the  arm  containing  the  read/write  head 
assembly. 
2. The  program  next  asks  for  and  accepts  a  list  containing  cylinder  numbers  (expected  to  be  in  a 
non-sorted,  random  order,  dictated  by  the  geographical  distribution  of  parts  of  a  file)  of  any 
length. You should not assume a fixed number of cylinders. These number of cylinders should be 
variable. 
3. Your program should NOT ask the user about the number of entries in the list of cylinders or use 
a  sentinel-based  approach  to  indicate  the  end  of  list  of  cylinders.  You  should  figure  out  some 
other technique to find out the number of entries. Also, you should not use storage structures of 
fixed and unnecessarily large sizes. 
4. The  program  then  offers  a  menu  to  the  user  with  three  choices:  ‘SCAN  algorithm’,  ‘C-SCAN 
algorithm’ and ‘Quit’. The program should keep coming back to this menu until the ‘Quit’ option 
is chosen. 
5. If  the  SCAN  algorithm  is  chosen,  the  program  runs  the  algorithm  and  reports  the  sequence  of 
cylinders traversed and the total number of cylinders traveled. The direction of travel is important 
for the SCAN algorithm only because the cylinders are serviced in either direction. 
6. If the C-SCAN algorithm is chosen, the program runs the algorithm and reports the sequence of 
cylinders  traversed  and  the  total  number  of  cylinders  traveled.  The  direction  of  travel  is  not 
important for the SCAN algorithm only because the cylinders are serviced only in one direction. 
However,  the  flyback  time  is  important  only  for  this  algorithm  because  after  servicing  the 
cylinders towards higher cylinder numbers, the R/W head arm flies back towards cylinder 0 and 
restarts 
7. The  program  should  clear  any  dynamically  allocated  memory  used  and  not  leave  any  memory 
leaks before exiting. 
8. The program should be tested on the UWF SSH server (or on the VM – only if the SSH server is 
down) before submission and submitted with a makefile. The instructor will test the program files 
by only running ‘make’ and ‘make clean’. Please make sure that the makefile also contains the 
name of the target executable file and the command to run the target. Entering the ‘make’ 
command on the command prompt should run the target executable file. 
