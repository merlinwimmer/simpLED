echo //Content of all files collected in one file > all.txt
cd setup
type functions.ino >> ../all.txt
type header.ino >> ../all.txt
type libraries.ino >> ../all.txt
type variables.ino >> ../all.txt
type setup.ino >> ../all.txt

cd ../apps
type *.ino >> ../all.txt

cd ../system
type *.ino >> ../all.txt