DATASET="Dataset"

make 

#make run < $DATASET/b_little_bit_of_everything.in
make run < $DATASET/a_example.in &> a_example.out
make run < $DATASET/b_little_bit_of_everything.in &> b_little_bit_of_everything.out
make run < $DATASET/c_many_ingredients.in &> c_many_ingredients.out
make run < $DATASET/d_many_pizzas.in &> d_many_pizzas.out
make run < $DATASET/e_many_teams.in &> e_many_teams.out

make clean