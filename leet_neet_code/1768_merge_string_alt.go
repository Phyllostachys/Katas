package leetneet

func mergeAlternately(word1 string, word2 string) string {
	i := 0
	res := ""
	for {
		if i == len(word1) || j == len(word2) {
			break
		}
		res = res + string(word1[i]) + string(word2[i])
		i++
	}
	if i == len(word1) {
		return res + word2[i:]
	} else {
		return res + word1[i:]
	}
}
