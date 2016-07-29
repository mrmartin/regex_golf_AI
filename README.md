# regex_golf_AI
Generate dataset of problems like the Regex Golf game. This allows training RNNs to play regex golf.

# dependency
[regldg](https://regldg.com/)
```
wget https://regldg.com/regldg-1.0.0.tar.gz
tar -zxvf regldg-1.0.0.tar.gz
cd regldg-1.0.0
```

# compile
```
g++ rand_text_generator.cpp -o rand_text_generator.bin
```

# create single problem instance
./rand_text_generator.bin 4 foo

# create random regex solutions (simple strings)
./regldg '--max-length=8' '--readable-output' '--num-words-output=1000' "[a-z]{3}" | shuf | head

# create entire dataset
while read regex; do ./rand_text_generator.bin 4 $regex; echo SOLUTION: $regex; done< <(./regldg '--max-length=8' '--readable-output' '--num-words-output=1000000' "[a-z]{3}" | shuf | head -10000) > foo_dataset
