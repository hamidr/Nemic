n=`grep "processor" /proc/cpuinfo | wc -l`;
for ((c=0; c<n ; c++))
do
    printf $c;
done
