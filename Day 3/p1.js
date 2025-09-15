/*Write a function getFactorialImpl ( choice="FORLOOP" ) ----it could be FORLOOP or RECUR
	Function Fact2(n1)
	Use recursion and print the factorial
	If the choice is FORLOOP return Fact1
	If the choice is RECUR then return Fact2
	Outside --- call let rv = getFactorialImpl("RECUR")
	rv(3)
	Rv = getFactorialImpl()
	rv(5)
*/

function getFactorialImpl(val) {
    switch (val) {
        case "RECUR":
            function Fact2(n2){
                if(n2 <= 1) return 1;
                return n2* Fact2(n2-1);
            }
            console.log(Fact2(5));
            break;
    
        default:
            function Fact1(n1) {
                result = 1;
                for(var i=1; i<=n1; i++){
                    result *= i;
                }
                console.log(result);
            }
            Fact1(15);
            break;
    }
}


getFactorialImpl();
// console.log(rv);

// Rv = getFactorialImpl();
// Rv();



