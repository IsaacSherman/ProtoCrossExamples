using ProtoCross.Demo;

var symmetric = ValueWithUncertaintyFactory.CreateSymmetric(10.0, 0.5);
var asymmetric = ValueWithUncertaintyFactory.CreateAsymmetric(10.0, 0.75, 0.25);

Console.WriteLine(FormattableString.Invariant(
    $"{symmetric.Value} ± {symmetric.PositiveUncertainty}"));

Console.WriteLine(FormattableString.Invariant(
    $"{asymmetric.Value} +{asymmetric.PositiveUncertainty} / -{asymmetric.NegativeUncertainty}"));