let  () =
	let x = read_int () in
	 try
 	while true do
  	 let a = read_int () in
   		if a<x then Printf.printf "%d\n" a
 		done;
 	()
	with
 	End_of_file -> ()
;;
