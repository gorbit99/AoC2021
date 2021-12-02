>>>>+>>>>> leave space for some variables
read in a 2 byte number
>>>>>+>>>>>+<<< set up loop
,[ while there is input
  ---------- subtract 10
  [>]>>[ if it's not zero it's not a \n
    <<++++++[-<------>]<-- subtract 38
    multiply the result by 10
	<<<<<<
	<[-<++++++++++>]<[->+<]>>
    [- while number is greater than 0
      >++++++++++ set up multiplier
      [- repeat 10 times
        >+[>]>>[ if we zeroed out
          <<<<<+>>>>>> increase MSB
        ]<<<<
      ]<
    ]
    >>[-<<+>>] copy result back
    add new input
	>>>>[-
      <<<<<<+ increase LSB
	  >>+<<[>]>>[ if we zeroed out
	    <<<+>>>> increase MSB
	  ]
	  <->>>>
	]
    ,>> read in new input
  ]
  <<
]
>>>-<<<<<

[[-] while we have a number
  read in another 2 byte number
  >>>>>+>>>>>+<<< set up loop
  ,[ while there is input
    ---------- subtract 10
    [>]>>[ if it's not zero it's not a \n
      <<++++++[-<------>]<-- subtract 38
      multiply the result by 10
	  <<<<<<
	  <[-<++++++++++>]<[->+<]>>
      [- while number is greater than 0
        >++++++++++ set up multiplier
        [- repeat 10 times
          >+[>]>>[ if we zeroed out
            <<<<<+>>>>>> increase MSB
          ]<<<<
        ]<
      ]
      >>[-<<+>>] copy result back
      add new input
      >>>>[-
        <<<<<<+ increase LSB
	    >>+<<[>]>>[ if we zeroed out
	      <<<+>>>> increase MSB
	    ]
	    <->>>>
	  ]
      ,>> read in new input
    ]
    <<
  ]
  >>>-<<<<<-<<<<<<<+>>>

  duplicate second value for next iteration
  [->>>>>>+<<<<<<<<+>>]<<[->>+<<]>>
  <[->>>>>>+<<<<<<<+>]<[->+<]>>

  subtract the second number from the first
  check if our second number is 0 or not
  >>+<<[>]>[>>+<<<]<<
  [<]>>>>[>>+<]
  <->>
  [[-]<<<< while there is a number left
    >>+<<[>]>>[<<<->>>>]<-<<
    -<<<<<
    [>]>>[ if the LSB is 0
      <<<[>]>>>[ if the MSB is 0
        <<<<<<<<<<+ increase our result counter LSB
        [>]>>[<<<+>>>>] if we zeroed out increase MSB
		>>>>+>+>>>>>[-]<[-]<
      ]
      <<<<->>>>
    ]
    <<<->>>>>
    check if our second number is 0 or not
    >>+<<[>]>[>>+<<<]<<
    [<]>>>>[>>+<]
    <->>
  ]

  cleanup
  <<<<<<<<<<[-]>[-]>>->>>>>>>>
  swap in next values
  [-<<<<<<<<<<<+>>>>>>>>>>>]
  >[-<<<<<<<<<<<+>>>>>>>>>>>]
  <<<<<<<<<<<
  check if we have a number
  >>+<<[>]>[>>+<<<]<<
  [<]>>>>[>>+<]
  <->>
]
<<<<<<<<<<-<<

printing the result
check if we have a number
>>+<<[>]>[>>+<<<]<<
[<]>>>>[>>+<]
<->>
[
  [[-] while we have a number
    <<+
  >>>>++++++++++ setting up counter
    [- repeat 10 times
      <<<<<<
      [>]>>[ if LSB is 0
        <<<[>]>>>[ if MSB is 0
          calculate remainder
  	  	  >+++++++++>>>[-<<<->>>]<<
  	  	  ++++++[-<++++++++>]<
		  [->>>>>>>>>>>>>>>[>>]>+[<<]<<<<<<<<<<<<<<]
		  >>>>>>>>>>>>>>>[>>]+[<<]<<<<<<<<<<<<<
  		  <<<+<+>>>>>
		  >>>+<<[>]>>[<<<->>>>]<<<<
		  >-<<
        ]
        <<<<->>>> decrement MSB
      ]
      <<<->>>>>>
    ]
    increment result
    <+
    >>+<<[>]>>[ if we zeroed out
      <<<+>>>> increment MSB
    ]
    <-<<<<<<<
    check if we still have a number left
    [>]>[>>+<<<]<<
    [<]>>>>[>>+<]
    <->>
  ]
  >[-<<<<<+>>>>>]<<<<<
  check if we still have a number left
  >>+<<[>]>[>>+<<<]<<
  [<]>>>>[>>+<]
  <->>
]
>>>>>>>>>>>>>>[>>]<[.<<] Write output