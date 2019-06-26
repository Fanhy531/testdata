const
  maxn=50+5;
var
  f,s:array[1..maxn,1..maxn,1..maxn,1..maxn] of longint;
  i,j,k,u,v,n,m:longint;
function min(a,b:longint):longint;

begin
  if a<b then exit(a) else exit(b);
end;


begin
  assign(input,'raisins.in');reset(input);
  assign(output,'raisins.sol');rewrite(output);
  readln(n,m);
  for i:=1 to n do
    for j:=1 to m do
      read(s[i,i,j,j]);
  for i:=n downto 1 do
    for j:=i to n do
      for u:=m downto 1 do
        for v:=u to m do
          if (i<>j)or(u<>v) then
            begin
              if i<j then s[i,j,u,v]:=s[i,i,u,v]+s[i+1,j,u,v]
              else s[i,j,u,v]:=s[i,j,u,u]+s[i,j,u+1,v];

              f[i,j,u,v]:=maxlongint;
              for k:=i to j-1 do
                f[i,j,u,v]:=min(f[i,j,u,v],f[i,k,u,v]+f[k+1,j,u,v]);
              for k:=u to v-1 do
                f[i,j,u,v]:=min(f[i,j,u,v],f[i,j,u,k]+f[i,j,k+1,v]);

              f[i,j,u,v]:=f[i,j,u,v]+s[i,j,u,v];
            end;
  writeln(f[1,n,1,m]);
  close(input);close(output);
end.
