let rec read_lines () =
    try let line = read_line () in
        int_of_string (line) :: read_lines()
    with
        End_of_file -> []

let rec replicate n cur =
	match n with
	| 0 -> []
	| _ -> cur :: replicate (n-1) cur
;;

let rec f n arr = 
	match arr with
	| [] -> []
	| h::t -> let h2 = replicate n h in
				h2 @ f n t
;;

let () =
    let n::arr = read_lines() in
    let ans = f n arr in
    List.iter (fun x -> print_int x; print_newline ()) ans
;;
