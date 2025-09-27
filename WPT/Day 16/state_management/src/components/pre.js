// Mount    lifecycle elements 
// Unmount
// Update


import { Component } from "react";

export default class Pre extends Component{
    constructor(props){
        super(props);      
   
    this.state={
        count:0,

    }
    console.log("Constructor is iniltialized")
    }

    componentDidMount() {
        console.log("Mounted");
    }
    
    shouldComponentUpdate(prevProps, prevState){
        console.log('componentDidUpdate: Component updated', prevProps, prevState);
        return true;
    }

    componentDidUpdate(prevProps , prevState){
        console.log("Component updated " ,prevProps ,prevState)
    }

    componentWillUnmount(prevProps , prevState){
       console.log("Component will be removed ", prevProps , prevState )
    }

    render() {
    console.log('Render: Component is rendering');
    return (
      <div>
        <p>Count: {this.state.count}</p>
        <button onClick={() => this.setState({ count: this.state.count + 1 })}>
          Increment
        </button>
      </div>
    );
  }
}