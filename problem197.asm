; Problem 197 - Mul Two
start:
  clc               ; clear carry flag
  ld r1             ; load r1 to accumulator
  rar               ; rotate right
  xch r1            ; xfer accumulator to r1
  jcn c0 loop       ; if carry 0 jump to loop
  inc r0            ; else increment r0
loop:
  jcn an start      ; jump to start if accumulator not zero