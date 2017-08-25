let rec fib n =
	match n with
	| 1 -> 0
	| 2 -> 1
	| _ -> (fib (n-1)) + (fib (n-2))
;;

let () =
    let n = read_int () in
    let fn = fib n in
    print_int fn
;;