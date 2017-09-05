let rec get_sum n =
    if n = 0 then 0
    else
        let d = Scanf.scanf " %d " (fun x -> x) in
        d + get_sum (n-1)
;;

let () =
    let n = read_int () in
    let sum = get_sum n in
    Printf.printf "%d\n" sum
;;
