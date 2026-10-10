## Exercise 00: Bitcoin Exchange

You have to create a program which outputs the value of a certain amount of bitcoin on a certain date.
This program must use a database in csv format which will represent bitcoin price over time. This database is provided with this subject.
The program will take as input a second database, storing the different prices/dates
to evaluate.

Your program must respect these rules:

• The program name is `btc`.

• Your program must `take a file as an argument`.

• Each line in this file must `use` the following `format: "date | value"`.

• A `valid date` will always be in the following `format: Year-Month-Day`.

• A valid value must be either a `float or a positive integer, between 0 and 1000`.


You must `use at least one container` in your code to validate this
exercise. You should handle possible errors with an appropriate
error message.

Here is an example of an input.txt file:
```text
$> head input.txt
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
$>
```
Your program will use the value in your input file.


Your program should display on the standard `output the result of the value multiplied by the exchange rate according to the date indicated in your database`.

If the date used in the input does not exist in your DB then you
must use the closest date contained in your DB. Be careful to use the
lower date and not the upper one.

The following is an example of the program’s use.
```
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>
```
Warning: The container(s) you use to validate this exercise will no
longer be usable for the rest of this module.



## Container class templates C++

### Sequence containers:
`array`	Array class (class template)                            You can use an array anywhere

`vector`	Vector (class template)                                 Good when you dont know the size of allocation

`deque`	Double ended queue (class template)                     Linked list

`forward_list`	Forward list (class template)

`list`	List (class template)

### Container adaptors:
`stack`	LIFO stack (class template)                             Pop! 

`queue`	FIFO queue (class template)

`priority_queue`	Priority queue (class template)


### Associative containers:
`set`	Set (class template)                                        A pair combo <age, 2>

`multiset`	Multiple-key set (class template)

`map`	Map (class template)                                        This is a Hash map! ==============> Creates a key bassically a pointer with a value that corresponds to another value

`multimap`	Multiple-key map (class template)                                                       Date =====> Multiplier. 

`Ordered`! 

### Unordered associative containers:

`unordered_set`	Unordered Set (class template)

`unordered_multiset`	Unordered Multiset (class template)

`unordered_map`	Unordered Map (class template)

`unordered_multimap`	Unordered Multimap (class template)