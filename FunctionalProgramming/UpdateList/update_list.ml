
let () =
	try
		while true do
			let x = read_int () in
			if x<0 then print_endline (string_of_int (-x))
			else print_endline (string_of_int x)
		done
	with
	End_of_file -> ()
;;