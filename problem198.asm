; Problem 198 - Prn Hex Str
start:
  ldm 9
  xch r5          ; store number '9' for later use
  jms $3f0        ; read character from input

  ld r2           ; load hi nibble into acc
  jcn az stop     ; jump to stop if acc = 0

  xch r0          ; xfer r2 to r0
  ld r3           
  xch r1          ; xfer r3 to r1

  ld r0           ; xfer r0 to r3
  xch r3
  ldm 3           ; put '3' in r2
  xch r2
  jms $3e0        ; print hi nibble to screen

  stc             ; set carry for subtraction
  ldm 9
  sub r1          ; 9 - r1
  jcn c1 digits   ; if carry = 1, print from set of 0 thru 9

  stc             ; else print from set of A thru F
  ld r1
  sub r5          ; r1 - 9
  xch r3          ; put result of subtraction into r3
  ldm 4
  xch r2          ; put $4 into r2
  jun print

digits:
  ld r1           ; xfer r1 to r3
  xch r3
  ldm 3           ; put '3' in r2
  xch r2

print:
  jms $3e0        ; print lo nibble to screen

  jun start       ; jump back to top
stop:
  nop