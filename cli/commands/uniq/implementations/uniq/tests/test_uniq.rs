#[cfg(test)]
mod test {
    use uniq::uniq::uniq;

    macro_rules! uniq_test {
    ($($name:ident: $value:expr,)*) => {
        $(
            #[test]
            fn $name() {
                let (input, expected) = $value;
                assert_eq!(expected, uniq(input));
            }
        )*
        }
    }

    uniq_test! {
        empty: (
            "",
            ""
        ),
        one_line: (
            "line",
            "line",
        ),
        two_different_line: (
            "line1\nline2",
            "line1\nline2",
        ),
        two_similar_lines: (
            "line1\nline1",
            "line1",
        ),
    }
}
