let mingle a b =
	let len = String.length a in
	String.init (2*len) (fun i -> if (i mod 2) = 0 then a.[i/2] else b.[i/2])
;;

let () = 
	let a = read_line () in
	let b = read_line () in
	let c = mingle a b in
	print_endline c
;;