# A script that launches gnuplot on the file result.dat

gnuplot<<EOF
plot "result.dat" u 1:2 w lp lw 2 title "uh", "result.dat" u 1:3 w l lw 2title "uex"
pause mouse keypress
EOF

