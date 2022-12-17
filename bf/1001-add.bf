add two numbers
store the numbers in c0 and c1
, enter a digit
	>, enter another digit

	make c 2 48
	48 is the ascii value of 0
	>> ++++ ++ c3 is 6
	[
		< ++++ ++++ increment c2 by 8
		> - decrement c3
	] iteration: 6

	now c2 is 48
	subtract 48 from c1
	to get the real number
	<[ start loop at c2
	< - decrement c1
	> - decrement c2
	] 

	now c1 is just the integer representation of the ascii
	let's do the same for c0
	> ++++ ++ c3 is 6
	[ start loop at c3
	< ++++ ++++ increment c2 by 8
	> - decrement c3
	]
	now c2 is 48

< [ start loop at c2
<< - decrement c0
>> - decrement c2
]
now c0 is also an int

add c1 to c0
< [ start loop at c1
< + increment c0
> - decrement c1
]

make c1 48
> ++++ ++ c2 is 6
[
	< ++++ ++++ add 8 to c1
	> - decrement c2
]

add 48 to c0 to get it's ascii value
< [ start loop at c1
	< + increment c0
	> - decrement c1
]

< . print answer
