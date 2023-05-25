#!/bin/bash

cd ..
make


#REQ2 TESTS
./ppd stock.dat coins.dat < ./testCasesM3/ppdTestREQ2.input > ./testCasesM3/ppdTestREQ2.actual_ppd_out
diff -w ./testCasesM3/ppdTestREQ2.output ./testCasesM3/ppdTestREQ2.actual_ppd_out
diff -w -y ./testCasesM3/ppdTestREQ2.expcoins ./coins.dat

#REQ3 TESTS
./ppd stock.dat coins.dat < ./testCasesM3/ppdTestREQ3.input > ./testCasesM3/ppdTestREQ3.actual_ppd_out
diff -w ./testCasesM3/ppdTestREQ3.output ./testCasesM3/ppdTestREQ3.actual_ppd_out
diff -w -y ./testCasesM3/ppdTestREQ3.expcoins ./coins.dat

#REQ4 TESTS
./ppd stock.dat coins.dat < ./testCasesM3/ppdTestREQ4.input > ./testCasesM3/ppdTestREQ4.actual_ppd_out
diff -w ./testCasesM3/ppdTestREQ4.output ./testCasesM3/ppdTestREQ4.actual_ppd_out
diff -w -y ./testCasesM3/ppdTestREQ4.expcoins ./coins.dat

#REQ5 TESTS
./ppd stock.dat coins.dat < ./testCasesM3/ppdTestREQ5.input > ./testCasesM3/ppdTestREQ5.actual_ppd_out
diff -w ./testCasesM3/ppdTestREQ5.output ./testCasesM3/ppdTestREQ5.actual_ppd_out
diff -w -y ./testCasesM3/ppdTestREQ5.expcoins ./coins.dat

#REQ6 TESTS
./ppd stock.dat coins.dat < ./testCasesM3/ppdTestREQ6.input > ./testCasesM3/ppdTestREQ6.actual_ppd_out
diff -w ./testCasesM3/ppdTestREQ6.output ./testCasesM3/ppdTestREQ6.actual_ppd_out
diff -w -y ./testCasesM3/ppdTestREQ6.expcoins ./coins.dat

#REQ7 TESTS
./ppd stock.dat coins.dat < ./testCasesM3/ppdTestREQ7.input > ./testCasesM3/ppdTestREQ7.actual_ppd_out
diff -w ./testCasesM3/ppdTestREQ7.output ./testCasesM3/ppdTestREQ7.actual_ppd_out
diff -w -y ./testCasesM3/ppdTestREQ7.expcoins ./coins.dat

#REQ8 TESTS
./ppd stock.dat coins.dat < ./testCasesM3/ppdTestREQ8.input > ./testCasesM3/ppdTestREQ8.actual_ppd_out
diff -w ./testCasesM3/ppdTestREQ8.output ./testCasesM3/ppdTestREQ8.actual_ppd_out
diff -w -y ./testCasesM3/ppdTestREQ8.expcoins ./coins.dat

#REQ9 TESTS
./ppd stock.dat coins.dat < ./testCasesM3/ppdTestREQ9.input > ./testCasesM3/ppdTestREQ9.actual_ppd_out
diff -w ./testCasesM3/ppdTestREQ9.output ./testCasesM3/ppdTestREQ9.actual_ppd_out
diff -w -y ./testCasesM3/ppdTestREQ9.expcoins ./coins.dat

#REQ10 TESTS
./ppd stock.dat coins.dat < ./testCasesM3/ppdTestREQ10.input > ./testCasesM3/ppdTestREQ10.actual_ppd_out
diff -w ./testCasesM3/ppdTestREQ10.output ./testCasesM3/ppdTestREQ10.actual_ppd_out
diff -w -y ./testCasesM3/ppdTestREQ10.expcoins ./coins.dat

#REQ11 TESTS
./ppd stock.dat coins.dat < ./testCasesM3/ppdTestREQ11.input > ./testCasesM3/ppdTestREQ11.actual_ppd_out
diff -w ./testCasesM3/ppdTestREQ11.output ./testCasesM3/ppdTestREQ11.actual_ppd_out
diff -w -y ./testCasesM3/ppdTestREQ11.expcoins ./coins.dat

#REQ12 TESTS
./ppd stock.dat coins.dat < ./testCasesM3/ppdTestREQ12.input > ./testCasesM3/ppdTestREQ12.actual_ppd_out
diff -w ./testCasesM3/ppdTestREQ12.output ./testCasesM3/ppdTestREQ12.actual_ppd_out
diff -w -y ./testCasesM3/ppdTestREQ12.expcoins ./coins.dat



