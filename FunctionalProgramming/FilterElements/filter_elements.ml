
let rec get_lst n =
	if n = 0 then []
	else
		let h =  Scanf.scanf " %d " (fun x -> x) in
		let x = (h,n) in
		x :: get_lst (n-1)
;;

let print lst =
	List.map fst lst
	|> List.map string_of_int 
	|> String.concat " "
	|> Printf.printf "%s\n"
;;

let rec qsort lst =
	match lst with
	| [] -> []
	| (hx,hy)::t -> 
				let l = qsort(List.filter (fun (x,y) -> x<hx) t) in
				let r = qsort(List.filter (fun (x,y) -> x>=hx) t) in
				l @ ((hx,hy) :: r)
;;

let rec qsort2 lst =
	match lst with
	| [] -> []
	| (hx,hy)::t -> 
				let l = qsort2(List.filter (fun (x,y) -> y>hy) t) in
				let r = qsort2(List.filter (fun (x,y) -> y<=hy) t) in
				l @ ((hx,hy) :: r);;

let rec loop t =
	if t = 0 then ()
	else
	begin
		let n = Scanf.scanf " %d " (fun x -> x) in
		let k = Scanf.scanf " %d " (fun x -> x) in
		let lst = qsort (get_lst n) in
		let res = ref [] in
		let i = ref 0 in
			while !i < n do
				let (x,y1) = (List.nth lst !i) in
				let y = ref y1 in
				let j = ref (!i+1) in
				(
					while !j<n && (fst (List.nth lst !j))=x do
						let y2 = snd (List.nth lst !j) in
							if y2 > !y then
								y := y2;
						j := !j + 1
					done;
					
					if !j - !i >= k then
						res := !res @ [(x,!y)];

					i := !j
				)
			done;
			if List.length !res = 0 then
				Printf.printf "-1\n"
			else
				print (qsort2 !res)

				(* print lst *)
		;
				
		loop (t-1);
	end
;;

let () =
	let t = read_int () in
	loop t
;;