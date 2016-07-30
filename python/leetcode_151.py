class Solution(object):

    def reverseWords(self, s):

        """

        :type s: str

        :rtype: str

        """
        # can use function s.strip() instead
        start=0
        while(s[start]==' '):
            start+=1
        end=len(s)-1
        while(s[end]==' '):
            end-=1
        s=s[start:end+1]
        wordlist=s.split(' ')
        words=[]
        for word in wordlist:
            if word: #not space/spaces
                words.append(word)
        return ' '.join(words[::-1])
if __name__=="__main__":
    s="  tomorrow is  another    day  "
    x=Solution()
    ans=x.reverseWords(s)
    print ans
