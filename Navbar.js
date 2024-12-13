import React from 'react';
import { NavLink } from 'react-router-dom'; // Use NavLink for active styles
import './Navbar.css'; // Import CSS

const Navbar = () => {
  return (
    <nav>
      <NavLink to="/" exact activeClassName="active">Home</NavLink>
      <NavLink to="/about" activeClassName="active">About</NavLink>
      <NavLink to="/contact" activeClassName="active">Contact</NavLink>
    </nav>
  );
};

export default Navbar;
