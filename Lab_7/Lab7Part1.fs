let square n =
    n * n

let isOdd n = 
    n % 2 <> 0

//test previous functions
// let x = square 2
// let test = isOdd 3

let sumOfOddSquares y = 
    y
    |>List.filter (isOdd)
    |>List.sumBy(square)

let inputList = [1; 2; 3; 4; 5;]
let y = sumOfOddSquares inputList

printfn "The sum of the odd squares in %A is %i" inputList y