
let rec swap lc rc cur h k =
	if h mod k = 0 then
	begin
		let tmp = lc.(cur) in
			lc.(cur) <- rc.(cur);
			rc.(cur) <- tmp
	end;
	if lc.(cur) != -1 then swap lc rc lc.(cur) (h+1) k;
	if rc.(cur) != -1 then swap lc rc rc.(cur) (h+1) k
;;


let rec print lc rc cur =
	if lc.(cur) != -1 then print lc rc lc.(cur);
	Printf.printf "%d " cur;
	if rc.(cur) != -1 then print lc rc rc.(cur)
;;

let () =
	let n = Scanf.scanf " %d " (fun x -> x) in
	let lc = Array.make (n+1) 0 in
	let rc = Array.make (n+1) 0 in
		for i = 1 to n do
			let l = Scanf.scanf " %d " (fun x -> x) in
			let r = Scanf.scanf " %d " (fun x -> x) in
				lc.(i) <- l;
				rc.(i) <- r
		done;
		let times = Scanf.scanf " %d " (fun x -> x) in
		let rec loop t =
			if t > 0 then
			begin
				let k = Scanf.scanf " %d " (fun x -> x) in
				swap lc rc 1 1 k;
				print lc rc 1;
				Printf.printf "\n";
				loop (t-1)
			end
		in loop times
;;
			