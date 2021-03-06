-- Module2
-- 1
SELECT * FROM Tracks WHERE Milliseconds >= 5000000;

-- 2
SELECT * FROM Invoices WHERE Total BETWEEN 5 AND 15;

-- 3
SELECT * FROM Customers WHERE State IN ('RJ', 'DF', 'AB',
'BC', 'CA', 'WA', 'NY');

-- 4
SELECT *
FROM Invoices
WHERE Total BETWEEN 1.00 AND 5.00
AND CustomerId IN (56, 58);

-- 5
SELECT *
FROM Tracks
WHERE Name LIKE 'All%';

-- 6
SELECT *
FROM Customers
WHERE Email LIKE 'J%gmail.com';

-- 7
SELECT *
FROM Invoices
WHERE BillingCity IN ('Brasília', 'Edmonton', 'Vancouver')
ORDER BY InvoiceId DESC;

-- 8
SELECT InvoiceId, COUNT(*)
FROM Invoices
GROUP BY CustomerId
ORDER BY COUNT(*) DESC;

-- 9
SELECT COUNT(*), tr.*
FROM Albums AS al INNER JOIN Tracks as tr
ON al.AlbumId = tr.AlbumId
GROUP BY al.AlbumID
HAVING COUNT(*) >= 12;

-- Module3
-- 1
SELECT TrackId, Name
FROM (SELECT *
      FROM Tracks AS tr INNER JOIN Albums AS al
      ON tr.AlbumId = al.AlbumId
      WHERE al.Title = 'Californication');

-- 2
SELECT COUNT(*), cs.FirstName, cs.LastName, cs.City, cs.Email
FROM Customers AS cs INNER JOIN Invoices AS iv
ON cs.CustomerId = iv.CustomerId
GROUP BY cs.CustomerId;

-- 3 すべてのアルバムのトラック名、アルバム、アーティストID、およびトラックIDを取得します。
SELECT al.Title, tr.Name, tr.AlbumId, al.ArtistId, tr.TrackId
FROM Albums AS al INNER JOIN Tracks as tr
ON al.AlbumId = tr.AlbumId;

-- 4 マネージャーの姓と、マネージャーに直属の従業員の姓を含むリストを取得します。
SELECT e.EmployeeId AS ManagerId,
       e.LastName AS ManagerName,
       e2.EmployeeId AS bukaId,
       e2.LastName AS bukaName
FROM Employees AS e INNER JOIN Employees AS e2
ON e.EmployeeId = e2.ReportsTo;

-- 5 アルバムを持っていないアーティストの名前とIDを見つけます。
SELECT ar.ArtistId AS aid, ar.Name, al.*
FROM Artists as ar LEFT OUTER JOIN Albums AS al
ON al.ArtistId = ar.ArtistId
WHERE al.AlbumId IS NULL;

-- 6 UNIONを使用して、従業員と顧客のすべての名と姓を降順で並べたリストを作成します。
SELECT FirstName, LastName
FROM Employees
UNION
SELECT FirstName, LastName
FROM Customers
ORDER BY LastName DESC;

-- 7 請求先都市と顧客都市に異なる都市がリストされている顧客があるかどうかを確認します。
SELECT iv.*
FROM Customers AS cs INNER JOIN Invoices AS iv
ON cs.CustomerId = iv.CustomerId
WHERE cs.City != iv.BillingCity;

-- Module4
-- 1 顧客IDのリストを顧客の氏名と住所とともに、都市と国を組み合わせて取得します。
-- これら2つの間にスペースを入れて、大文字にしてください。
SELECT CustomerId, FirstName, LastName, UPPER(City) || ' ' || UPPER(Country)
FROM Customers;

-- 2 従業員の名の最初の4文字と従業員の姓の最初の2文字を組み合わせて、新しい従業員ユーザーIDを作成します。
-- 新しいフィールドを小文字にし、各ステップを引いて作業を表示します。
SELECT SUBSTR(FirstName, 1, 4) || SUBSTR(LastName, 1, 2) AS new_user_id
FROM Employees;

-- 3 現在の日付関数を使用して、15年以上会社で働いている従業員のリストを表示します。姓の昇順で並べ替えます。
SELECT *
FROM Employees
WHERE CURRENT_DATE - HireDate >= 15
ORDER BY LastName ASC;

-- 4 顧客テーブルをプロファイリングし、次の質問に答えます。null値を持つ列はありますか？
SELECT sum(case when Phone is null then 1 else 0 end) phone,
       sum(case when Company is null then 1 else 0 end) Company,
       sum(case when Address is null then 1 else 0 end) Address,
       sum(case when PostalCode is null then 1 else 0 end) PostalCode,
       sum(case when Fax is null then 1 else 0 end) Fax,
       sum(case when FirstName is null then 1 else 0 end) FirstName
FROM Customers;

-- 5 最も顧客の多い都市を見つけ、降順でランク付けします。
SELECT City, COUNT(*)
FROM Customers
GROUP BY City
-- HAVING COUNT(*) = 2
ORDER BY COUNT(*) DESC;

-- 6 顧客の請求書IDを名と姓と組み合わせて、顧客の請求書IDを作成します。
-- クエリは、firstname、lastname、invoiceIDの順序で並べます。
SELECT cs.FirstName || cs.LastName || iv.InvoiceId AS new_invoice_id
FROM Customers AS cs INNER JOIN Invoices AS iv
ON cs.CustomerId = iv.CustomerId
WHERE new_invoice_id LIKE 'AstridGruber%';
