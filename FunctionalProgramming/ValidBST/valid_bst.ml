
let less arr st en v =
	if st > en then true
	else
	begin
		let flag = ref true in
			for i = st to en do
				if arr.(i) >= v then
					flag := false
			done;
			!flag
	end
;;

let greater arr st en v =
	if st > en then true
	else
	begin
		let flag = ref true in
			for i = st to en do
				if arr.(i) <= v then
					flag := false
			done;
			!flag
	end
;;

let find arr st en v =
	let pos = ref st in
	let flag = ref true in
		while !pos <= en && arr.(!pos) <v do
			pos := !pos + 1
		done;
		if !pos = st then
		begin
			if greater arr st en v = true then !pos
			else -1
		end
		else
		begin
			if !pos > en then
			begin
			 	if less arr st en v = true then !pos
			 	else -1
			end 
			else 
			begin
				if less arr st (!pos-1) v = false then -1
				else
					if greater arr !pos en v = true then !pos
					else -1
			end
		end
;;

let rec check arr st en =
	if st >= en then true
	else
	begin
		let pos = find arr (st+1) en arr.(st) in
			if pos < 0 then false
			else
			begin
				let l = check arr (st+1) (pos-1) in
					if l = false then false
					else (check arr pos en)
			end
	end
;;

let read_arr n =
	let res = Array.make n 0 in
		for i = 0 to (n-1) do
			let x = Scanf.scanf " %d " (fun x -> x) in
			res.(i) <- x
		done;
		res
;;

let rec loop t = 
	if t > 0 then
	begin
		let n = Scanf.scanf " %d " (fun x -> x) in
		let arr = read_arr n in
			if (check arr 0 (n-1)) = true then Printf.printf "YES\n"
			else Printf.printf "NO\n";
			loop (t-1)
	end
	else ()
;;

let () =
	let t = Scanf.scanf " %d " (fun x -> x) in
	loop t
;;