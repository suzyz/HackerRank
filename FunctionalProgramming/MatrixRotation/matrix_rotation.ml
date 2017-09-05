(* open Core.std *)

let get_loc x y dist x1 x2 y1 y2 perimeter =
	let n = x2 - x1 + 1 in
	let m = y2 - y1 + 1 in
	let num = ref 0 in
	if x = x1 then num := y - y1
	else
	begin
		if x = x2 then num := n + m-2 + y2 - y
		else
		begin
			if y = y2 then num := y2 - y1 + x - x1
			else num:= 2*m + n - 3 + x2 - x
		end
	end;
	(* Printf.printf "num:%d\n" !num; *)
	num := (!num + dist) mod perimeter;
	let a = ref 0 in
	let b = ref 0 in
	if !num < m then
	begin
		a := x1; b := y1 + !num
	end
	else
	begin
		if !num < m + n -1 then
		begin
			a := x1 + !num - (y2 - y1);
			b := y2;
		end
		else
		begin
			if !num < 2*m + n -2 then
			begin
				a := x2;
				b := y2 - (!num - (m + n -2))
			end
			else
			begin
				a := x2 - (!num - (2*m + n -3));
				b := y1
			end
		end
	end;
	(!a,!b)
;;

let make_matrix n m =
	let res = Array.make n (Array.make m 0) in
		for i = 0 to (n-1) do
			res.(i) <- Array.make m 0
		done;
		res
;;		

let () =
	let n = Scanf.scanf " %d " (fun x -> x) in
	let m = Scanf.scanf " %d " (fun x -> x) in
	let r = Scanf.scanf " %d " (fun x -> x) in
	let matrix = make_matrix n m in
	let backup = make_matrix n m in
		for i = 0 to (n-1) do
			for j = 0 to (m-1) do
				let x = Scanf.scanf " %d " (fun x -> x) in
					matrix.(i).(j) <- x;
					backup.(i).(j) <- x
			done
		done;
		let x1 = ref 0 in
		let y1 = ref 0 in
		let x2 = ref (n-1) in
		let y2 = ref (m-1) in
		let perimeter = ref (2*(m+n-2)) in
		while !x1 < !x2 && !y1 < !y2 do
			(* Printf.printf "perimeter:%d\n" !perimeter; *)
			let dist = r mod !perimeter in
			if dist > 0 then
			begin
				(* Printf.printf "range: %d %d %d %d\n" !x1 !x2 !y1 !y2; *)
				for j = (!y1) to (!y2) do
					let (a,b) = get_loc !x1 j dist !x1 !x2 !y1 !y2 !perimeter in
					(* Printf.printf "%d %d %d %d\n" !x1 j a b *)
					matrix.(!x1).(j) <- backup.(a).(b)
				done;
				for j = !y1 to !y2 do
					let (a,b) = get_loc !x2 j dist !x1 !x2 !y1 !y2 !perimeter in
					matrix.(!x2).(j) <- backup.(a).(b)
					(* Printf.printf "%d %d %d %d\n" !x2 j a b *)
				done;
				if !x1 + 1 < !x2  then
				begin
					for i = (!x1+1) to (!x2-1) do
					let (a,b) = get_loc i !y1 dist !x1 !x2 !y1 !y2 !perimeter in
					matrix.(i).(!y1) <- backup.(a).(b)
					(* Printf.printf "%d %d %d %d\n" i !y1 a b *)
					done;
					for i = (!x1+1) to (!x2-1) do
					let (a,b) = get_loc i !y2 dist !x1 !x2 !y1 !y2 !perimeter in
					matrix.(i).(!y2) <- backup.(a).(b)
					(* Printf.printf "%d %d %d %d\n" i !y2 a b *)
					done
				end	
			end;
			x1 := !x1 + 1;
			x2 := !x2 - 1;
			y1 := !y1 + 1;
			y2 := !y2 - 1;
			perimeter := !perimeter - 8
		done;

		for i = 0 to (n-1) do
			for j = 0 to (m-1) do
				Printf.printf "%d " matrix.(i).(j)
			done;
			Printf.printf "\n"
		done
;;
		