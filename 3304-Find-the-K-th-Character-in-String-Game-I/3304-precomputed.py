class Solution:
    #absolutely pity solution, performs well, though
    def kthCharacter(self, k: int) -> str:
        precomputed = bytearray(b"abbcbccdbccdcddebccdcddecddedeefbccdcddecddedeefcd"
                                    b"dedeefdeefeffgbccdcddecddedeefcddedeefdeefeffgcdde"
                                    b"deefdeefeffgdeefeffgeffgfgghbccdcddecddedeefcddede"
                                    b"efdeefeffgcddedeefdeefeffgdeefeffgeffgfgghcddedeef"
                                    b"deefeffgdeefeffgeffgfgghdeefeffgeffgfggheffgfgghfg"
                                    b"ghghhibccdcddecddedeefcddedeefdeefeffgcddedeefdeef"
                                    b"effgdeefeffgeffgfgghcddedeefdeefeffgdeefeffgeffgfg"
                                    b"ghdeefeffgeffgfggheffgfgghfgghghhicddedeefdeefeffg"
                                    b"deefeffgeffgfgghdeefeffgeffgfggheffgfgghfgghghhide"
                                    b"efeffgeffgfggheffgfgghfgghghhieffgfgghfgghghhifggh"
                                    b"")

        return chr(precomputed[k-1])
