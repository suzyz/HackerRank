
let rec read_map n = 
	if n = 1 then
		let (x,y) = Scanf.scanf " %d %d" (fun x y -> (x,y)) in
			[(x,y)]
	else
	begin
		let (x,y) = Scanf.scanf " %d %d " (fun x y -> (x,y)) in
		(x,y) :: read_map (n-1)
	end
;;

let check maping n =
	let res = ref true in
	begin
		for i = 0 to (n-1) do
			let (x1,y1) = List.nth maping i in
				for j = (i+1) to (n-1) do
					let (x2,y2) = List.nth maping j in
						if x1 = x2 && y1 <> y2 then
							res := false
				done
		done;

		!res		
	end
;;

let rec print_them maping m n = 
	if m = n then ()
	else
	begin
		let (x,y) = List.nth maping m in
		Printf.printf "%d %d\n" x y	;
		print_them maping (m+1) n
	end
;;

let rec loop t =
	if t = 0 then ()
	else
	begin
		let n = Scanf.scanf " %d " (fun x -> x) in
		let maping = read_map n in
		(* print_them maping 0 n  *)

		let res = check maping n in
		if res = true then Printf.printf "YES\n"
		else Printf.printf "NO\n"
		;
		loop (t-1)
	end
;;

let () =
	let t = Scanf.scanf " %d " (fun x -> x) in
	loop t
;;