    |   Page:  0    |   Page:  1    |   Page:  2    |   Page:  3    |   Page:  4    |   Page:  5    |   Page:  6    |   Page:  7    |   Page:  8    |   Page:  9    |   Page: 10    |   Page: 11    |   Page: 12    |   Page: 13    |   Page: 14    |   Page: 15    |   Page: 16    |   Page: 17    
  0 | pace ^ 1      | pace > 1      | nop           | pace v 1      | jz            | pace v 2      | nop           | nop           | pace v 1      | nop           | pace < 1      | jz page       | nop           | nop           | nop           | nop           | pace ^ 1      | nop           |
  1 | pace > 1      | pace ^ 1      | nop           | getch         | push 0x61 'a' | pace ^ 2      | pace > 1      | nop           | nop           | nop           | pace v 1      | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
  2 | print         | nop           | nop           | pace v 1      | nop           | pace ^ 1      | nop           | nop           | dup           | nop           | dup           | nop           | nop           | nop           | nop           | nop           | pace > 1      | pace v 1      |
  3 | print         | nop           | pace > 1      | pace rand 1   | pace < 1      | mod           | nop           | nop           | push 0        | nop           | push 2        | nop           | nop           | nop           | nop           | nop           | print         | nop           |
  4 | print         | nop           | pace > 1      | pace rand 1   | pace < 1      | sub           | nop           | nop           | push 4        | nop           | mod           | nop           | nop           | nop           | nop           | nop           | print         | nop           |
  5 | print         | nop           | pace > 1      | pace rand 1   | pace < 1      | push 3        | nop           | nop           | secr push 23d | nop           | push 1        | nop           | nop           | nop           | nop           | nop           | print         | nop           |
  6 | print         | nop           | pace > 1      | pace rand 1   | pace < 1      | push 0x71 'q' | nop           | nop           | sub           | nop           | add           | nop           | nop           | nop           | nop           | nop           | print         | nop           |
  7 | print         | nop           | pace > 1      | pace rand 1   | pace < 1      | push 6        | nop           | pace v 1      | jz page       | pace v 1      | push 2        | nop           | nop           | nop           | nop           | nop           | print         | nop           |
  8 | print         | nop           | pace > 1      | pace rand 1   | pace < 1      | jz            | nop           | dup           | nop           | nop           | mod           | nop           | nop           | nop           | nop           | nop           | print         | nop           |
  9 | print         | nop           | nop           | dup           | nop           | print_int     | nop           | push 1        | nop           | nop           | swap          | nop           | nop           | nop           | nop           | nop           | print         | nop           |
  a | print         | nop           | nop           | push 2        | nop           | sub           | nop           | push 4        | nop           | nop           | push 2        | nop           | nop           | nop           | nop           | nop           | print         | nop           |
  b | print         | nop           | nop           | push 5        | nop           | sub           | nop           | secr push 1fc | nop           | nop           | div           | nop           | nop           | nop           | nop           | nop           | print         | nop           |
  c | print         | nop           | nop           | mul           | nop           | push 0x72 'r' | nop           | sub           | nop           | nop           | dup           | nop           | nop           | nop           | nop           | nop           | secret_loop   | nop           |
  d | print         | nop           | nop           | sub           | nop           | push 0x29 ')' | pace ^ 1      | jz page       | nop           | pace v 1      | push 0        | nop           | nop           | nop           | nop           | nop           | push 0x47 'G' | nop           |
  e | print         | jz            | nop           | pace < 1      | nop           | jz            | nop           | nop           | nop           | nop           | push 2        | nop           | nop           | nop           | nop           | nop           | push 0x72 'r' | nop           |
  f | print         | nop           | nop           | nop           | nop           | push 0x74 't' | nop           | nop           | nop           | nop           | secr push 2d5 | pace v 1      | nop           | pace < 1      | nop           | nop           | push 0x61 'a' | nop           |
 10 | print         | nop           | nop           | nop           | nop           | push 8        | nop           | nop           | nop           | nop           | mod           | nop           | nop           | nop           | nop           | nop           | push 0x74 't' | nop           |
 11 | secret_loop   | pace > 1      | pop           | pop           | nop           | push 0x61 'a' | nop           | nop           | nop           | nop           | swap          | nop           | pace v 1      | nop           | nop           | nop           | push 0x7a 'z' | nop           |
 12 | push 0x54 'T' | nop           | nop           | nop           | nop           | push 2        | nop           | nop           | nop           | nop           | push 0        | push 2        | swap          | nop           | nop           | nop           | not           | nop           |
 13 | push 0x79 'y' | nop           | nop           | nop           | nop           | jz            | nop           | nop           | nop           | nop           | push 2        | push 5        | push 5        | nop           | nop           | nop           | not           | nop           |
 14 | self_modify   | nop           | nop           | nop           | nop           | push 0x73 's' | nop           | nop           | nop           | nop           | secr push 2da | secr push 321 | mod           | nop           | nop           | nop           | not           | nop           |
 15 | push 0x65 'e' | nop           | nop           | nop           | nop           | secret_loop   | nop           | nop           | nop           | nop           | div           | dup           | pace v 1      | nop           | nop           | pace < 1      | secret_loop   | nop           |
 16 | nop           | nop           | nop           | nop           | nop           | push 0x27 ''' | nop           | nop           | nop           | nop           | push 1        | push 0        | push 9        | nop           | nop           | nop           | nop           | nop           |
 17 | self_modify   | nop           | nop           | nop           | nop           | pop           | nop           | nop           | nop           | nop           | add           | push 2        | push 2        | nop           | pace > 1      | nop           | nop           | pace v 1      |
 18 | push 0x61 'a' | nop           | nop           | nop           | nop           | pace v 2      | nop           | nop           | nop           | nop           | nop           | secr push 325 | add           | nop           | print         | nop           | nop           | push 5        |
 19 | push 0x73 's' | nop           | nop           | pace v 1      | mod           | push 2        | nop           | nop           | nop           | nop           | pace < 1      | sub           | dup           | nop           | print         | nop           | nop           | push 5        |
 1a | push 0x73 's' | nop           | nop           | push 2        | nop           | push 1        | nop           | nop           | nop           | nop           | push 0        | nop           | push 7        | nop           | print         | nop           | nop           | add           |
 1b | push 0x77 'w' | nop           | nop           | push 0        | nop           | dup           | nop           | nop           | nop           | nop           | push 2        | nop           | add           | nop           | print         | nop           | nop           | print         |
 1c | push 0x6f 'o' | nop           | nop           | push 2        | nop           | push 0x75 'u' | nop           | nop           | nop           | nop           | secr push 2e2 | nop           | swap          | nop           | print         | nop           | nop           | exit          |
 1d | push 0x72 'r' | nop           | nop           | secr push f2  | nop           | push 1        | nop           | nop           | nop           | nop           | pace < 2      | nop           | self_modify   | nop           | print         | add           | nop           | nop           |
 1e | push 0x64 'd' | nop           | nop           | mul           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | pace > 1      | pace ^ 1      | secret_loop   | push 1        | nop           | nop           |
 1f | dup           | nop           | nop           | pace > 1      | mul           | swap          | nop           | nop           | nop           | nop           | pace v 1      | nop           | nop           | nop           | push 0x57 'W' | secr push 448 | nop           | nop           |
 20 | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | push 2        | nop           | nop           | nop           | push 0x72 'r' | swap          | nop           | nop           |
 21 | secret_loop   | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | mul           | nop           | nop           | nop           | push 0x6f 'o' | add           | nop           | nop           |
 22 | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | add           | nop           | nop           | nop           | push 0x6e 'n' | push 7        | nop           | nop           |
 23 | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | add           | nop           | nop           | nop           | secr push 405 | dup           | nop           | nop           |
 24 | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | pace > 1      | pace v 1      | nop           | nop           | nop           | not           | add           | nop           | nop           |
 25 | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | sub           | nop           | nop           | nop           | secret_loop   | push 2        | nop           | nop           |
 26 | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | pace > 1      | nop           | nop           | nop           | jz            | push 9        | nop           | nop           |
 27 | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | pace > 1      | pace ^ 1      | nop           | nop           |
 28 | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 29 | push 0x48 'H' | push 0x54 'T' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 2a | push 0x65 'e' | push 0x68 'h' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 2b | push 0x6c 'l' | push 0x69 'i' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 2c | push 0x6c 'l' | push 0x73 's' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 2d | push 0x6f 'o' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 2e | push 0        | push 0x63 'c' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 2f | push 0        | push 0x61 'a' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 30 | push 0x41 'A' | push 0x6e 'n' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 31 | push 0        | push 0x6e 'n' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 32 | push 0        | push 0x6f 'o' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 33 | push 0        | push 0x74 't' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 34 | push 0x46 'F' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 35 | push 0x52 'R' | push 0x62 'b' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 36 | push 0x45 'E' | push 0x65 'e' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 37 | push 0x45 'E' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 38 | push 8        | push 0x72 'r' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 39 | push 1        | push 0x75 'u' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 3a | push 17       | push 0x6e 'n' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 3b | push 0        | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 3c | push 144      | push 0x69 'i' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 3d | push 0x62 'b' | push 0x6e 'n' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 3e | push 17       | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 3f | push 0        | push 0x44 'D' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 40 | push 0x43 'C' | push 0x4f 'O' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 41 | push 0x29 ')' | push 0x53 'S' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 42 | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 43 | push 2        | push 0x6d 'm' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 44 | push 0        | push 0x6f 'o' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 45 | push 1        | push 0x64 'd' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 46 | push 2        | push 0x65 'e' | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           | nop           |
 