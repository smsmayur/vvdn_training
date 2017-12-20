#for i in hello 1 * 2 goodbye
#for i in *	    #this is wildcards it is used for display all files in pwd
for i in $(seq 2)   #for set iteration
do
    echo "looping no. i is  set to $i "
done
