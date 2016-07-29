# regex_golf_AI
Generate dataset of problems like the [Regex Golf game](http://regex.alf.nu/). This allows training RNNs to play regex golf.

# dependency
[regldg](https://regldg.com/)
and
[char_rnn](https://github.com/karpathy/char-rnn) for trying to learn

# compile
```
wget https://regldg.com/regldg-1.0.0.tar.gz
tar -zxvf regldg-1.0.0.tar.gz
cd regldg-1.0.0
make
g++ rand_text_generator.cpp -o rand_text_generator.bin
```

# create single problem instance
```
./rand_text_generator.bin 4 foo
```

# create random regex solutions (simple strings)
```
./regldg '--max-length=8' '--readable-output' '--num-words-output=1000' "[a-z]{3}" | shuf | head
```

# create entire dataset
```
while read regex; do ./rand_text_generator.bin 4 $regex; echo SOLUTION: $regex; done< <(./regldg '--max-length=8' '--readable-output' '--num-words-output=1000000' "[a-z]{3}" | shuf | head -10000) > foo_dataset
```

# train with [char_rnn](https://github.com/karpathy/char-rnn)
```
th train.lua -checkpoint_every 10000 -max_epochs 25000 -dropout 0.5 -seq_length 40 -num_layers 2 -batch_size 1000 -input_h5 my_data.h5 -input_json my_data.json
```

Because the network doesn't learn, it shows that RNNs do not learn rules which are not character-specific
