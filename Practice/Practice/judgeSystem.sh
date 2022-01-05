DATASET="Dataset"
PATH_JUDGE="Judge_System_Code"
FILENAME="best_score.out"

printf "###############################\n"
printf "##   GOOGLE HASH CODE 2020   ##\n"
printf "##        Auto Checker       ##\n"
printf "###############################\n"

printf "Dataset A ... "
python3 $PATH_JUDGE/get_score.py  $DATASET/a_example.txt a.out $FILENAME

printf "Dataset B ... "
python3 $PATH_JUDGE/get_score.py  $DATASET/b_read_on.txt b.out $FILENAME

printf "Dataset C ... "
python3 $PATH_JUDGE/get_score.py  $DATASET/c_incunabula.txt c.out $FILENAME

printf "Dataset D ... "
python3 $PATH_JUDGE/get_score.py  $DATASET/d_tough_choices.txt d.out $FILENAME

printf "Dataset E ... "
python3 $PATH_JUDGE/get_score.py  $DATASET/e_so_many_books.txt e.out $FILENAME

printf "Dataset F ... "
python3 $PATH_JUDGE/get_score.py  $DATASET/f_libraries_of_the_world.txt f.out $FILENAME

python3 $PATH_JUDGE/get_sum.py $FILENAME