let rec gcd a b =
	if (a mod b) = 0 then b
    else gcd b (a mod b)
;;

let () =
	Scanf.scanf "%d %d" (fun a b -> Printf.printf "%d\n" (gcd a b))
;;