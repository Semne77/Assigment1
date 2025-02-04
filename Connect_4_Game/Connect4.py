def setup(): # Set up the board
    b=[[],[],[],[],[],[]]
    for j in range(7): # j is the index for the columns (files)
        for i in range(6): # i is the index for the rows
            b[i]=b[i]+[0]
    return b

def present(b):
    for i in range(6):
        print(b[i])

def colheight(b,c): # Column height.  Returns actual height (number of tokens in that column)
    k=0
    while k<6 and b[k][c]==0:
        k=k+1
    return 6-k

def pt(b,p,c): # Place token p in column c
    h=colheight(b,c)
    b[5-h][c]=p
    return b


def vc(b,p,c): # Cathy Carrillo Govea and Simon Holst
    ans=0
    h=colheight(b,c)
    if h==4:
        t=b[2][c]+b[3][c]+b[4][c]+b[5][c]
        m=b[2][c]*b[3][c]*b[4][c]*b[5][c]
        if m!=0 and t==4*p:
            ans=1
    if h==5:
        t=b[1][c]+b[2][c]+b[3][c]+b[4][c]
        m=b[1][c]*b[2][c]*b[3][c]*b[4][c]
        if m!=0 and t==4*p:
            ans=1
    if h==6:
        t=b[0][c]+b[1][c]+b[2][c]+b[3][c]
        m=b[0][c]*b[1][c]*b[2][c]*b[3][c]
        if m!=0 and t==4*p:
            ans=1
    return ans


def hc(b,p,c): # Andrew Frazier and William Schalley
    ans=0
    h=colheight(b,c)
    d=6-h
    if c==0:
        m=b[d][0]*b[d][1]*b[d][2]*b[d][3]
        t=b[d][0]+b[d][1]+b[d][2]+b[d][3]
        if m!=0 and t==4*p:
            ans=1
    elif c==1:
        m1=b[d][0]*b[d][1]*b[d][2]*b[d][3]
        t1=b[d][0]+b[d][1]+b[d][2]+b[d][3]
        m2=b[d][1]*b[d][2]*b[d][3]*b[d][4]
        t2=b[d][1]+b[d][2]+b[d][3]+b[d][4]
        if m1!=0 and t1==4*p:
            ans=1
        elif m2!=0 and t2==4*p:
            ans=1
    elif c==2:
        m1=b[d][0]*b[d][1]*b[d][2]*b[d][3]
        t1=b[d][0]+b[d][1]+b[d][2]+b[d][3]
        m2=b[d][1]*b[d][2]*b[d][3]*b[d][4]
        t2=b[d][1]+b[d][2]+b[d][3]+b[d][4]
        m3=b[d][2]*b[d][3]*b[d][4]*b[d][5]
        t3=b[d][2]+b[d][3]+b[d][4]+b[d][5]
        if m1!=0 and t1==4*p:
            ans=1
        elif m2!=0 and t2==4*p:
            ans=1
        elif m3!=0 and t3==4*p:
            ans=1
    elif c==3:
        m1=b[d][0]*b[d][1]*b[d][2]*b[d][3]
        t1=b[d][0]+b[d][1]+b[d][2]+b[d][3]
        m2=b[d][1]*b[d][2]*b[d][3]*b[d][4]
        t2=b[d][1]+b[d][2]+b[d][3]+b[d][4]
        m3=b[d][2]*b[d][3]*b[d][4]*b[d][5]
        t3=b[d][2]+b[d][3]+b[d][4]+b[d][5]
        m4=b[d][3]*b[d][4]*b[d][5]*b[d][6]
        t4=b[d][3]+b[d][4]+b[d][5]+b[d][6]
        if m1!=0 and t1==4*p:
            ans=1
        elif m2!=0 and t2==4*p:
            ans=1
        elif m3!=0 and t3==4*p:
            ans=1
        elif m4!=0 and t4==4*p:
            ans=1
    elif c==4:
        m1=b[d][1]*b[d][2]*b[d][3]*b[d][4]
        t1=b[d][1]+b[d][2]+b[d][3]+b[d][4]
        m2=b[d][2]*b[d][3]*b[d][4]*b[d][5]
        t2=b[d][2]+b[d][3]+b[d][4]+b[d][5]
        m3=b[d][3]*b[d][4]*b[d][5]*b[d][6]
        t3=b[d][3]+b[d][4]+b[d][5]+b[d][6]
        if m1!=0 and t1==4*p:
            ans=1
        elif m2!=0 and t2==4*p:
            ans=1
        elif m3!=0 and t3==4*p:
            ans=1
    elif c==5:
        m1=b[d][2]*b[d][3]*b[d][4]*b[d][5]
        t1=b[d][2]+b[d][3]+b[d][4]+b[d][5]
        m2=b[d][3]*b[d][4]*b[d][5]*b[d][6]
        t2=b[d][3]+b[d][4]+b[d][5]+b[d][6]
        if m1!=0 and t1==4*p:
            ans=1
        elif m2!=0 and t2==4*p:
            ans=1
    else:
        m1=b[d][3]*b[d][4]*b[d][5]*b[d][6]
        t1=b[d][3]+b[d][4]+b[d][5]+b[d][6]
        if m1!=0 and t1==4*p:
            ans=1
    return ans


def d2(b,p): # Rebeca Garcia and William Pender
    ans=0
    h=colheight(b,2)
    if h==6:
        t=b[0][2]+b[1][3]+b[2][4]+b[3][5]
        m=b[0][2]*b[1][3]*b[2][4]*b[3][5]
        if t==4*p and m!=0:
            ans=1
    if h==5:
        t=b[1][2]+b[2][3]+b[3][4]+b[4][5]
        m=b[1][2]*b[2][3]*b[3][4]*b[4][5]
        if t==4*p and m!=0:
            ans=1
        t=b[1][2]+b[2][3]+b[3][4]+b[0][1]
        m=b[1][2]*b[2][3]*b[3][4]*b[0][1]
        if t==4*p and m!=0:
            ans=1
        t=b[1][2]+b[0][3]+b[2][1]+b[3][0]
        m=b[1][2]*b[0][3]*b[2][1]*b[3][0]
        if t==4*p and m!=0:
            ans=1
    if h==4:
        t=b[2][2]+b[3][3]+b[4][4]+b[5][5]
        m=b[2][2]*b[3][3]*b[4][4]*b[5][5]
        if t==4*p and m!=0:
            ans=1
        t=b[2][2]+b[3][3]+b[4][4]+b[1][1]
        m=b[2][2]*b[3][3]*b[4][4]*b[1][1]
        if t==4*p and m!=0:
            ans=1
        t=b[2][2]+b[3][3]+b[1][1]+b[0][0]
        m=b[2][2]*b[3][3]*b[1][1]*b[0][0]
        if t==4*p and m!=0:
            ans=1
        t=b[2][2]+b[3][1]+b[0][4]+b[1][3]
        m=b[2][2]*b[3][1]*b[0][4]*b[1][3]
        if t==4*p and m!=0:
            ans=1
        t=b[2][2]+b[3][1]+b[4][0]+b[1][3]
        m=b[2][2]*b[3][1]*b[4][0]*b[1][3]
        if t==4*p and m!=0:
            ans=1
    if h==3:
        t=b[3][2]+b[2][3]+b[1][4]+b[0][5]
        m=b[3][2]*b[2][3]*b[1][4]*b[0][5]
        if t==4*p and m!=0:
            ans=1
        t=b[3][2]+b[2][3]+b[4][1]+b[1][4]
        m=b[3][2]*b[2][3]*b[4][1]*b[1][4]
        if t==4*p and m!=0:
            ans=1
        t=b[2][3]+b[3][2]+b[5][0]+b[4][1]
        m=b[2][3]*b[3][2]*b[5][0]*b[4][1]
        if t==4*p and m!=0:
            ans=1
        t=b[3][2]+b[2][1]+b[5][4]+b[4][3]
        m=b[3][2]*b[2][1]*b[5][4]*b[4][3]
        if t==4*p and m!=0:
            ans=1
        t=b[3][2]+b[2][1]+b[1][0]+b[4][3]
        m=b[3][2]*b[2][1]*b[1][0]*b[4][3]
        if t==4*p and m!=0:
            ans=1
    if h==2:
        t=b[2][4]+b[5][1]+b[4][2]+b[3][3]
        m=b[2][4]*b[5][1]*b[4][2]*b[3][3]
        if t==4*p and m!=0:
            ans=1
        t=b[2][4]+b[1][5]+b[4][2]+b[3][3]
        m=b[2][4]*b[1][5]*b[4][2]*b[3][3]
        if t==4*p and m!=0:
            ans=1
        t=b[4][2]+b[5][3]+b[2][0]+b[3][1]
        m=b[4][2]*b[5][3]*b[2][0]*b[3][1]
        if t==4*p and m!=0:
            ans=1
    if h==1:
        t=b[2][5]+b[3][4]+b[5][2]+b[4][3]
        m=b[2][5]*b[3][4]*b[5][2]*b[4][3]
        if t==4*p and m!=0:
            ans=1
    return ans


def d4(b,p): # Rebeca Garcia and William Pender
    ans=0
    h=colheight(b,4)
    if h==6:
        t=b[0][4]+b[3][1]+b[2][2]+b[1][3]
        m=b[0][4]*b[3][1]*b[2][2]*b[1][3]
        if t==4*p and m!=0:
            ans=1
    if h==5:
        t=b[1][4]+b[0][5]+b[3][2]+b[2][3]
        m=b[1][4]*b[0][5]*b[3][2]*b[2][3]
        if t==4*p and m!=0:
            ans=1
        t=b[4][1]+b[1][4]+b[3][2]+b[2][3]
        m=b[4][1]*b[1][4]*b[3][2]*b[2][3]
        if t==4*p and m!=0:
            ans=1
        t=b[1][4]+b[0][3]+b[2][5]+b[3][6]
        m=b[1][4]*b[0][3]*b[2][5]*b[3][6]
        if t==4*p and m!=0:
            ans=1
    if h==4:
        t=b[2][4]+b[0][2]+b[1][3]+b[3][5]
        m=b[2][4]*b[0][2]*b[1][3]*b[3][5]
        if t==4*p and m!=0:
            ans=1
        t=b[2][4]+b[4][6]+b[1][3]+b[3][5]
        m=b[2][4]*b[4][6]*b[1][3]*b[3][5]
        if t==4*p and m!=0:
            ans=1
        t=b[2][4]+b[0][6]+b[1][5]+b[3][3]
        m=b[2][4]*b[0][6]*b[1][5]*b[3][3]
        if t==4*p and m!=0:
            ans=1
        t=b[4][2]+b[2][4]+b[1][5]+b[3][3]
        m=b[4][2]*b[2][4]*b[1][5]*b[3][3]
        if t==4*p and m!=0:
            ans=1
        t=b[4][2]+b[2][4]+b[5][1]+b[3][3]
        m=b[4][2]*b[2][4]*b[5][1]*b[3][3]
        if t==4*p and m!=0:
            ans=1
    if h==3:
        t=b[3][4]+b[2][3]+b[1][2]+b[0][1]
        m=b[3][4]*b[2][3]*b[1][2]*b[0][1]
        if t==4*p and m!=0:
            ans=1
        t=b[3][4]+b[2][3]+b[1][2]+b[4][5]
        m=b[3][4]*b[2][3]*b[1][2]*b[4][5]
        if t==4*p and m!=0:
            ans=1
        t=b[3][4]+b[2][3]+b[5][6]+b[4][5]
        m=b[3][4]*b[2][3]*b[5][6]*b[4][5]
        if t==4*p and m!=0:
            ans=1
        t=b[4][3]+b[2][5]+b[1][6]+b[3][4]
        m=b[4][3]*b[2][5]*b[1][6]*b[3][4]
        if t==4*p and m!=0:
            ans=1
        t=b[4][3]+b[5][2]+b[2][5]+b[3][4]
        m=b[4][3]*b[5][2]*b[2][5]*b[3][4]
        if t==4*p and m!=0:
            ans=1
    if h==2:
        t=b[4][4]+b[3][5]+b[2][6]+b[5][3]
        m=b[4][4]*b[3][5]*b[2][6]*b[5][3]
        if t==4*p and m!=0:
            ans=1
        t=b[4][4]+b[5][5]+b[2][2]+b[3][3]
        m=b[4][4]*b[5][5]*b[2][2]*b[3][3]
        if t==4*p and m!=0:
            ans=1
        t=b[4][4]+b[1][1]+b[2][2]+b[3][3]
        m=b[4][4]*b[1][1]*b[2][2]*b[3][3]
        if t==4*p and m!=0:
            ans=1
    if h==1:
        t=b[5][4]+b[4][3]+b[2][1]+b[3][2]
        m=b[5][4]*b[4][3]*b[2][1]*b[3][2]
        if t==4*p and m!=0:
            ans=1
    return ans


def playgame(b):
    j=0
    done=0
    while j<42 and done<1:
        p=j%2+1
        print("Token",j+1,"-- Player",p,":")
        valid=0
        while valid<1:
            c = int(input("Choose a column (0 through 6): "))
            if c>=0 and c<=6 and colheight(b,c)<6:
                pt(b,p,c)
                valid=1
            else:
                print("Not a valid play. Player",p,": Try again.")

        if j>5: # Check for wins starting with the 7-th token played
            # Check for vertical win
            if vc(b,p,c)==1:
                done=1
                print("Player",p,"has a vertical win from play in column",c,".")

            # Check for horizontal win
            elif hc(b,p,c)==1:
                done=1
                print("Player",p,"has a horizontal win from play in column",c,".")

            # Check for diagonal wins
            else:
                if c==2:
                    if d2(b,p)==1:
                        done=1
                        print("Player",p,"has diagonal win from play in column",c,".")
                elif c==4:
                    if d4(b,p)==1:
                        done=1
                        print("Player",p,"has diagonal win from play in column",c,".")

        print("")
        present(b)
        print("")
        j=j+1
    if done>0:
        print("Congrats!")
    else:
        print("No winner.")

b=setup()
playgame(b)
