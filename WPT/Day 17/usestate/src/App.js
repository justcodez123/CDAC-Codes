import logo from './logo.svg';
import './App.css';
import Counter1 from './Component/usestate';
import Counter2 from './Component/useeffect';
import DataList from './Component/list';

function App() {
  return (
    <div className="App">
     <Counter1></Counter1>
     <Counter2></Counter2>
     <DataList></DataList>
    </div>
  );
}

export default App;
