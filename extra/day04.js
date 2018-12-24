function is_prime(nb) {
	if (nb < 2) {
		return (false);
	}
	for (let i = 2; i <= (nb / 2); i++) {
		if (nb % i == 0) {
			return (false);
		}
	}
	return (true);
}

function find_next_prime(nb) {
	for (; !is_prime(nb); nb++) {}
	return nb;
}

console.log(find_next_prime(50));
