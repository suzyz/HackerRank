
let () =
	let n = ref 0 in
	try ( while true do let x = read_int () in n:= (!n+1) done )
	with End_of_file -> print_int !n
;;