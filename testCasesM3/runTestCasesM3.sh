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

#Invalid Input TESTS
./ppd stock.dat coins.dat < ./testCasesM3/ppdTestInvalidInput.input > ./testCasesM3/ppdTestInvalidInput.actual_ppd_out
diff -w ./testCasesM3/ppdTestInvalidInput.output ./testCasesM3/ppdTestInvalidInput.actual_ppd_out
diff -w -y ./testCasesM3/ppdTestInvalidInput.expcoins ./coins.dat



