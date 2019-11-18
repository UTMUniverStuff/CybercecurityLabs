# Task
Same task as lab2, but in bash

## Sample input:
~~~bash
matrix $>matrix a 5 5 5
matrix $>fillrand a 10 99
matrix $>matrix b 5 5 5
matrix $>fillrand b 10 99
matrix $>apply a_plus_b a + b
matrix $>apply a_div_b a / b
matrix $>out a_plus_b
a_plus_b[0,0,0]=103
a_plus_b[0,0,1]=122
a_plus_b[0,0,2]=148
a_plus_b[0,0,3]=178
...
a_plus_b[4,4,3]=74
a_plus_b[4,4,4]=122
matrix $>out a_div_b
a_div_b[0,0,0]=3
a_div_b[0,0,1]=2
a_div_b[0,0,2]=1
...
a_div_b[4,4,4]=2
~~~
