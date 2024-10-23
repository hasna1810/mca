document.getElementById('registrationForm').addEventListener('submit', function(event) {
    // Prevent form submission
    event.preventDefault();

    // Clear previous error messages
    document.getElementById('usernameError').innerText = '';
    document.getElementById('emailError').innerText = '';
    document.getElementById('passwordError').innerText = '';

    // Get form values
    const username = document.getElementById('username').value;
    const email = document.getElementById('email').value;
    const password = document.getElementById('password').value;

    let valid = true;

    // Validate username
    if (username.length < 3) {
        document.getElementById('usernameError').innerText = 'Username must be at least 3 characters long.';
        valid = false;
    }

    // Validate email
    const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (!emailPattern.test(email)) {
        document.getElementById('emailError').innerText = 'Please enter a valid email address.';
        valid = false;
    }

    // Validate password
    if (password.length < 6) {
        document.getElementById('passwordError').innerText = 'Password must be at least 6 characters long.';
        valid = false;
    }

    // If all validations pass, submit the form (or perform further actions)
    if (valid) {
        alert('Registration successful!');
        // You can submit the form here or perform an AJAX request
        // this.submit(); // Uncomment this line to submit the form
    }
});
