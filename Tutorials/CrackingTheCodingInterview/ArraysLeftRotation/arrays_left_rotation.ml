
let get_arr n = 
	let arr = Array.make n 0 in
		for i = 0 to (n-1) do
			arr.(i) <- Scanf.scanf " %d " (fun x -> x)
		done;
		arr
;;

let () = 
	let n = Scanf.scanf " %d " (fun x -> x) in
	let d = Scanf.scanf " %d " (fun x -> x mod n) in
	let arr = get_arr n in
		for i = 0 to (n-1) do
			Printf.printf "%d " arr.((i+d) mod n)
		done
;;