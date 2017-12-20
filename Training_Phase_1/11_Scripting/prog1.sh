    echo "enter path e.g.(../mayur/temp/d_name)"
    read d_path
    echo "enter size e.g.(../mayur/d_name)"
    read d_size
    echo "\n\n"
     find $d_path -size $d_size
