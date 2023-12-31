import html from "../core.js";
import { connect } from "../store.js";
import Header from "./Header.js";
import Todolist from "./Todolist.js";
import Footer from "./Footer.js";
const connector =connect()
function App({todos}){
    return html`
    <section class="todoapp">
        ${Header()}
        ${todos.length > 0 &&Todolist()}
        ${todos.length > 0 &&Footer()}
    </section>
        `
}
export default connector(App)