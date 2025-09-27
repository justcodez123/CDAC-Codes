import {useState} from "react";

function Calculator(props)
{ 
    const [num1, setNum1] = useState(props.num1);
    const [num2, setNum2] = useState(props.num2);
    const [num3, setNum3] = useState(props.num3);

    const handleNum1Change = (e) => {
        setNum1((e.target.value));
    };

    const handleNum2Change = (e) => {
        setNum2((e.target.value));
    };

    const handleNum3Change = (e) => {
        setNum3((e.target.value));
    };

    const addition = num1 + num2 + num3;
    const multiplication = num1 * num2 * num3;
    const division = num2 !== 0 ? num1 / num2 : "Cannot divide by zero";
    const subtraction = num1 - num2 - num3;

    return(
        <div className={props.className || "calculator"}>
            <h1><i>{props.title || "CALCULATOR"}</i></h1>
            <div>
                <label>
                    Number 1:
                    <input 
                        type="number" 
                        value={num1} 
                        onChange={handleNum1Change}
                        placeholder="Enter first number"
                    />
                    
                </label>
                
            </div>
            <div>
                <label>
                    Number 2:
                    <input 
                        type="number" 
                        value={num2} 
                        onChange={handleNum2Change}
                        placeholder="Enter second number"
                    />
                </label>
            </div>
            <div>
                <label>
                    Number 3:
                    <input 
                        type="number" 
                        value={num3} 
                        onChange={handleNum3Change}
                        placeholder="Enter third number"
                    />
                </label>
            </div>
            <h2>Addition is: {addition}</h2>
            <h2>Subtraction is: {subtraction}</h2>
            <h2>Multiplication is: {multiplication}</h2>
            <h2>Division is: {division}</h2>
        </div>
    );
}
 export default Calculator;

