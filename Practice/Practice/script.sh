DATASET="Dataset"

make 
#make run < $DATASET/a_example.txt
#make run < $DATASET/b_read_on.txt
#make run < $DATASET/c_incunabula.txt

make run < $DATASET/a_example.txt &> a.out
make run < $DATASET/b_read_on.txt &> b.out
make run < $DATASET/c_incunabula.txt &> c.out
make run < $DATASET/d_tough_choices.txt &> d.out
make run < $DATASET/e_so_many_books.txt &> e.out
make run < $DATASET/f_libraries_of_the_world.txt &> f.out

make clean

#Executes the Judge System
bash judgeSystem.sh
