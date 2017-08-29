
let rec evaluate x i fac pow =
	if i = 10 then 0.0
	else
	begin
		let newFac =(fac *. (float_of_int (i+1))) in
		let newPow = (pow *. x) in
		(pow /. fac) +. (evaluate x (i+1) newFac newPow)
	end
;;

let rec loop n =
	if n = 0 then ()
	else
		let x = read_float () in
		let v = evaluate x 0 1.0 1.0 in
		Printf.printf "%.4f\n" v;
		(* print_endline (string_of_float v); this will output 1.0 as 1. *)
		loop (n-1)
;;

let () =
	let n = read_int () in
	loop n
;;