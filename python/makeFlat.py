def makeFlat(tuplesOfTuples):
    if isinstance(tuplesOfTuples, tuple):
        def makeFlatIterV1(currTuplesOfTuples):
            if isinstance(currTuplesOfTuples, tuple):
                if len(currTuplesOfTuples) == 0:
                    return ()
                return makeFlatIterV1(currTuplesOfTuples[0]) + makeFlatIterV1(currTuplesOfTuples[1:])
            else:
                return (currTuplesOfTuples,)

        def makeFlatIterV2(finalTuple, mainTuple):
            if len(mainTuple) == 0:
                return finalTuple
            auxTuple = ()
            for each in mainTuple:
                if isinstance(each, tuple):
                    auxTuple = auxTuple+each
                else:
                    finalTuple = finalTuple + (each,)
            return makeFlatIterV2(finalTuple, auxTuple)
        print("make flat v1:")
        print(makeFlatIterV1(tuplesOfTuples))
        print("make flat v2:")
        print(makeFlatIterV2((), tuplesOfTuples))
    else:
        raise Exception("The argument is not a tuple!")


makeFlat((1, 3, (4, 5, 6)))
makeFlat((((((1,))))))
makeFlat((1,))
makeFlat((1, 2, 4, 5, 6))
makeFlat((1, 3, (4, 5, 6, (1, 34, 56, (15, 25, (13, 354,
         (100, 200, (500, (400, (234, 34, (134, 35354, (134,))))))))))))
makeFlat(((1, 3, (4, 5, 6, (1, 34, 56, (15, 25, (13, 354,
         (100, 200, (500, (400, (234, 34, (134, 35354, (134,))))))))))), 1, 3, (4, 5, 6, (1, 34, 56, (15, 25, (13, 354,
                                                                                                               (100, 200, (500, (400, (234, 34, (134, 35354, (134,))))))))))))
