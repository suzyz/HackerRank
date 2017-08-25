let rec printNHello n =
	print_string "Hello World\n";
	if n>1 then printNHello (n-1)
;;

let () =
	let n = read_int() in
	printNHello n
;;